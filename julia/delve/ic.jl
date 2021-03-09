@test_delve(
            query = """
            def p = 5

            @static
            ic { forall(x in p: Int(x)) }
            """,
            debug = true,
            expected = Dict( :p => [5] )
           )

# @test_delve(
#             query = """
#             def b = a
# 
#             @static
#             ic { forall(x: b(x, _) implies x % 2 = 0) }
#             """,
#             debug = true,
#             inputs = Dict( :a => [(2, 1), (4, 2)] ),
#             expected = Dict( :b => [(2, 1), (4, 2)] )
#            )
