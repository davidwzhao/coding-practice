x = 4.2
# println(typeof(x))
# println(typeof(typeof(x)))

function factorial(x)
    if x <= 1
        return 1
    else
        return x * factorial(x - 1)
    end
end

# println(factorial(6))

# zero(::Array{Int64}) = 0
# zero(::Array{Float64}) = 0.0

l = [1, 3, 4.65, 2, 23.0]
# function add(l::Array)
#     sum_so_far = zero(l)
# 
#     # for i in 1:length(l)
#     #     sum_so_far += l[i]
#     # end
#     
#     for i in l
#         sum_so_far += i
#     end
# 
#     return sum_so_far
# end


include("sum.jl")
import .Sum
println(Sum.add(l))
