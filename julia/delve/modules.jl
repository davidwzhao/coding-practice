# @test_delve(
#     query = """
#     @debug
#     module hello
#         def a = 1; 2; 3
#         def b(y, x) = a(x) and y = x
#     end
# 
#     with hello use b
# 
#     // ic { count[b] = 3 }
#     def result_b = b
#     """,
#     expected = Dict(:result_b => [(1, 1), (2, 2), (3, 3)]))


@test_delve(
    query = """
    @inline
    module graph_algorithms[V, E]
        def outdegree[x in V] = count[E[x]] <++ 0
        def indegree[x in V] = count[y: E(y, x)] <++ 0
        def reflexive_closure = E ∪ (x, x from x in V)
        def reverse(y, x) = E(x, y)
    end

    module sample_graph
        def node(x) = edge(x, _) or edge(_, x)
        def edge = ('a', 'b'); ('a', 'c'); ('b', 'c')
    end

    with sample_graph use node, edge
    with graph_algorithms[node, edge]
        use outdegree, indegree, reverse, reflexive_closure

    ic { outdegree['a'] = 2 }
    ic { outdegree['b'] = 1 }
    ic { outdegree['c'] = 0 }

    ic { indegree['a'] = 0 }
    ic { indegree['b'] = 1 }
    ic { indegree['c'] = 2 }

    ic { count[reflexive_closure] = 6 }
    ic { count[reverse] = 3 }

    def result_a = outdegree
    """,
    expected = Dict(:result_a => [('a', 2), ('b', 1), ('c', 0)]))
