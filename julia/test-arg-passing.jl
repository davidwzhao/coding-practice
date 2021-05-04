mutable struct A
    vals::Vector{Vector{Int}}
end

mutable struct Sub_A
    vals::Vector{Int}
end

function plus(sub_a::Sub_A)
    vals = sub_a.vals

    for i in 1:length(vals)
        vals[i] += 1
    end

    return Sub_A(vals)
end

a = A([[1, 2], [4, 5]])

sub_a = Sub_A(a.vals[1])

sub_a = plus(sub_a)

println("sub_a: ", sub_a)
println("a: ", a)
