@test_delve(
        query = """
        def R = {(1, 26); (2, 26); (3, 28); (1, 36); (2, 13)}

        @inline
        def sum_nearest[R, index] =
            sum[i, s:
                // the value at index i contributes (1 - abs[i - index]) proportion of the final
                // percentile
                s = v * (1 - abs[i - index]) and

                // sort[y, x...] instead of sort[last[R]] to handle duplicate values
                sort[y, x...: R(x..., y)](i, v, rest...) and

                // only for the values surrounding index
                index - 1 <= i <= index + 1
                from v, rest...
            ]

        @inline
        def index_1[R, p] =
            // index is a float value
            (p * (count[R] - 1) / 100.0 + 1)

        def res = sum_nearest[R, index_1[R, 70]]
        """,
        # debug = true,
        expected = Dict( :res => [27.6] )
       )
