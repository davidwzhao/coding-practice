@test_delve(
            query = """
            def output = a : exists(b : input(a, b))
            """,
            inputs = Dict( :input => [(0,0), (1,1)] ),
            expected = Dict( :output => [0, 1] )
           )

@test_delve(
            query = """
            def netsales[x, y, z] = sales[x, y, z] - returns[x, y, z]
            """,
            inputs = Dict( :sales => [(2, 4, 6, 8)], :returns => [(2, 4, 6, 7)] ),
            expected = Dict( :netsales => [(2, 4, 6, 1)] )
           ) 

@test_delve(
            query = """
            def state = input_state

            ic = count[input_state] = 1

            @inline def operator = x, y, res: (res = x + y)
            @inline def operator = x, y, res: (res = x - y)
            @inline def operator = x, y, res: (res = y - x)
            @inline def operator = x, y, res: (res = x * y)
            @inline def operator = x, y, res: y != 0 and x % y = 0 and (res = x / y)
            @inline def operator = x, y, res: x != 0 and y % x = 0 and (res = y / x)

            def state(res, c, d) = exists a, b: state(a, b, c, d) and operator(a, b, res)
            def state(res, b, d) = exists a, c: state(a, b, c, d) and operator(a, c, res)
            def state(res, b, c) = exists a, d: state(a, b, c, d) and operator(a, d, res)
            def state(res, a, d) = exists b, c: state(a, b, c, d) and operator(b, c, res)
            def state(res, a, c) = exists b, d: state(a, b, c, d) and operator(b, d, res)
            def state(res, a, b) = exists c, d: state(a, b, c, d) and operator(c, d, res)

            def state(res, b) = exists a, c: state(a, b, c) and operator(a, c, res)
            def state(res, c) = exists a, b: state(a, b, c) and operator(a, b, res)
            def state(res, a) = exists b, c: state(a, b, c) and operator(b, c, res)

            def state(res) = exists a, b: state(a, b) and operator(a, b, res)

            def found_result = state(24)
            """,
            inputs = Dict( :input_state => [(6, 3, 2, 1)] ),
            expected = Dict( :found_result => Tuple{}[()] )
           )

# @test_delve(
#             query = """
#             def a(x + 1) = Int(x) and a(x) and x < 4
#             """,
#             inputs = Dict( :a => [1] ),
#             expected = Dict( :a => [1, 2, 3] )
#            )

@test_delve(
            query = """
            @inline
            def equals = x, y: (x = y)

            def equal_vals(x, y) = a(x, y) and equals(x, y)
            """,
            inputs = Dict( :a => [(1, 2), (2, 2)] ),
            expected = Dict( :equal_vals => [(2, 2)] )
           )

