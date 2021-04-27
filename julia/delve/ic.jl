# @test_delve(
#             query = """
#             def p = 5
# 
#             @static
#             ic { forall(x in p: Int(x)) }
#             """,
#             # debug = true,
#             expected = Dict( :p => [5] )
#            )
# 
# @test_delve(
#             query = """
#             def b = a
# 
#             @static
#             ic { forall(x: b(x, _) implies x % 2 = 0) }
#             """,
#             # debug = true,
#             inputs = Dict( :a => [(2, 1), (4, 2)] ),
#             expected = Dict( :b => [(2, 1), (4, 2)] )
#            )
# 
# 
# @test_delve(
#             query = """
#             def p = 5.5
# 
#             @static
#             ic { forall(x in p: Int(x)) }
#             """,
#             debug = true,
#             # expected = Dict( :p => [5] )
#            )

@test_delve(
            query = """
            def p = 3; 4; 5
            def q = 6; 7; 8
            def r(x, y) = p(x) and q(y) and x + y = 20

            // @trace_front_specialize
            ic { forall(x, y: r(x, y) implies Float(x) and Float(y)) }

            // def h = 3.14
            // ic { forall(x in h: Float(x)) }

            """,
            # debug = true
           )

@test_delve(
            query = """
            def p = 3; 4; 5
            def q = 6; 7; 8

            def r(x) = p(x) and q(x)
            def s(x, y) = p(x) and q(y)

            def t = exists(x: p(x) and q(x))

            // ic { not t() }

            // ic { forall(x in r: Float(x)) and forall(x, y: s(x, y) implies Float(x) and Float(y)) and forall(y: s(_, y) implies String(y)) }

            // def b() = exists x: p(x) and Float(x)
            ic { forall(x, y: s(x, y) implies (x > y)) }
            """,
            # debug = true
           )

@test_delve(
            query = """
            def p = 3; 4; 5

            ic { forall(x in p: Float(p)) }
            """,
            expect_abort = true
            # debug = true
           )
