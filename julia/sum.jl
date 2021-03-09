module Sum

zero(::Array{T}) where T <: Integer = 0
zero(::Array{T}) where T <: AbstractFloat = 0.0

function add(l::Array{T}) where T <: Number
    sum_so_far = zero(l)
    
    for i in l
        sum_so_far += i
    end

    return sum_so_far
end

end
