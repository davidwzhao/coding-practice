A = Datalog.Trie(Vector{Any}([(3, 2), (2, 3), (1, 4), (1, 3), (5, 4), (5, 5), (3, 6)]))
B = Datalog.Trie(Vector{Any}([(2, 3), (4, 2), (3, 4), (5, 3)]))
C = Datalog.Trie(Vector{Any}([(1, 2), (3, 3), (4, 3), (6, 3)]))

iter_A = Datalog.TrieIterator(A)
iter_B = Datalog.TrieIterator(B)
iter_C = Datalog.TrieIterator(C)

# We want to express the join R(x, y, z) :- A(x, y), B(y, z), C(x, z), x = z, so we pick the variable order x, y, z

#= 
# Create a unary join for variable x
x = Datalog.UnaryJoin([iter_A, iter_C])

# Create a unary join for variable y
y = Datalog.UnaryJoin([Datalog.open(iter_A), iter_B])

# Create a unary join for variable z
z = Datalog.UnaryJoin([Datalog.open(iter_B), Datalog.open(iter_C)])
=#

#=
b = iter_B
b_depth = 0

while true
    if !Datalog.is_end(b)
        for i in 1:b_depth
            print("  ")
        end
        println("key: ", Datalog.key(b))
    end

    if Datalog.is_end(b)
        if b_depth <= 0
            break
        end

        global b = Datalog.next(Datalog.up(b))
        global b_depth -= 1
        continue
    end

    n = Datalog.open(b)

    if b_depth >= 1
        global b = Datalog.next(b)
        continue
    end

    global b_depth += 1
    global b = n
end
=#

iter_xz = Datalog.EqualityIterator()

iters = Vector{Datalog.GenericIterator{Any,Tuple{}}}([iter_A, iter_B, iter_C, iter_xz])
join = Datalog.GenericJoin(iters, Dict(1 => [1, 3, 4], 2 => [1, 2], 3 => [2, 3, 4]))

current_key = []

# walk the tree
while true
    println("depth: ", join.depth, ", key: ", Datalog.key(join))

    if Datalog.is_end(join)
        if join.depth < 1
            break
        end

        global join = Datalog.next(Datalog.up(join))
        continue
    end

    next = Datalog.open(join)

    if next === nothing
        global join = Datalog.next(join)
        continue
    end

    global join = next
end


#=
# initialize
while true
    next = Datalog.open(join)

    println("opening, depth: ", next.depth)

    if next === nothing
        println("next is nothing, depth: ", join.depth)
        break
    end

    if Datalog.key(next) === nothing
        # this happens if there is no value for the join at this level
        global join = Datalog.next(join)
        # global join = Datalog.up(next)
        println("join's key: ", Datalog.key(join), ", join's depth: ", join.depth)
        current_key[length(current_key)] = Datalog.key(join)
        println("current key: ", current_key)
        continue
    end

    push!(current_key, Datalog.key(next))
    println("current key in progress: ", current_key)
    global join = next
end

println("first key: ", current_key)

println("current depth: ", join.depth)

# walk
while true
    global join = Datalog.next(join)

    println("is next join at end?? ", Datalog.is_end(join))
    
    if Datalog.is_end(join)
        global join = Datalog.up(join)
        if join.depth < 0
            break
        end

        pop!(current_key)
        continue
    else
        current_key[length(current_key)] = Datalog.key(join)
    end

    # walk back down
    while true
        next = Datalog.open(join)
        if next === nothing
            break
        end

        push!(current_key, Datalog.key(next))
        global join = next
    end

    println(current_key)
end
=#
