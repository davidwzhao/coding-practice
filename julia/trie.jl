module Tries

import DataStructures: SortedDict, SortedSet
import DataStructures: startof, advance, deref_key, deref_value
import DataStructures: pastendsemitoken, beforestartsemitoken

# TrieNode
# =============================================================================

mutable struct TrieNode{K}
    value::Union{Nothing, K}
    children::SortedDict{K, TrieNode{K}}
    is_end::Bool
end

function TrieNode{K}() where {K}
    return TrieNode(nothing, SortedDict{K, TrieNode{K}}(), false)
end

# Trie
# =============================================================================

mutable struct Trie{K}
    # Root is always an empty TrieNode
    root::TrieNode{K}
end

# TODO add ordering parameter
function Trie{K}() where {K}
    return Trie{K}(TrieNode{K}())
end

# Modification
# =============================================================================

function Base.insert!(t::Trie{K}, key) where {K}
    node = t.root

    for k in key
        if !(k in node.children)
            new_node = TrieNode{K}(k, SortedDict{K, TrieNode{K}}(), false)
            node.children[k] = new_node
            node = new_node
        else
            node = node.children[k]
        end
    end

    node.is_end = true

    return nothing
end

# function Base.getindex(t::Trie{K,V}, key)::Trie{K,V} where {K,V}
#     return t.children[key]
# end

# Trie iterator interface
# =============================================================================

struct TrieIterator{K}
    parent::Union{TrieIterator{K},Nothing}
    node::TrieNode{K}
    semitoken::Any
end

function TrieIterator(node::Trie{K}) where {K}
    parent = nothing
    return TrieIterator{K}(parent, node.root, startof(node.root.children))
end

function key(it::TrieIterator{K}) where {K}
    return deref_key((it.node.children, it.semitoken))
end

# function value(it::TrieIterator{K,V}) where {K,V}
#     return deref_value((it.node.children, it.semitoken)).value
# end

function next(it::TrieIterator{K})::TrieIterator{K} where {K}
    return TrieIterator{K}(it.parent, it.node, advance((it.node.children, it.semitoken)))
end

function open(it::TrieIterator{K})::TrieIterator{K} where {K}
    parent = it
    child_node = deref_value((it.node.children, it.semitoken))
    return TrieIterator{K}(parent, child_node, startof(child_node.children))
end

function up(it::TrieIterator{K})::TrieIterator{K} where {K}
    return it.parent
end

function is_end(it::TrieIterator{K})::Bool where {K}
    return (it.semitoken == pastendsemitoken(it.node.children))
end

function is_root(it::TrieIterator{K})::Bool where {K}
    return it.parent === nothing
end

# Trie value iterator
# =============================================================================

struct TrieValueIterator{K}
    depth::Int
    current_key::Vector{K}
    is_end::Bool
    trie_iterator::TrieIterator{K}
end

function TrieValueIterator(depth::Int64, node::Trie{K}) where {K}
    current_key = Vector{K}()

    iterator = TrieIterator(node)

    # Go to most child iterator
    while !isempty(iterator.node.children)
        push!(current_key, key(iterator))
        iterator = open(iterator)
        depth += 1
    end

    return TrieValueIterator{K}(depth - 1, current_key, false, up(iterator))
end

function TrieValueIterator(node::Trie{K}) where {K}
    return TrieValueIterator(1, node)
end

function key(it::TrieValueIterator{K}) where {K}
    return it.current_key
end

function next(it::TrieValueIterator{K}) where {K}
    depth = it.depth
    current_key = it.current_key
    parent = it.trie_iterator

    if !is_end(next(parent))
        next_iter = next(parent)
        current_key[length(current_key)] = key(next_iter)
        return TrieValueIterator(depth, current_key, false, next_iter)
    else
        pop!(current_key)

        at_end = false
        while is_end(next(parent))
            pop!(current_key)
            parent = up(parent)
            depth -= 1
        end

        while !isempty(parent.node.children)
            push!(current_key, key(parent))
            parent = open(parent)
            depth += 1
        end

        return TrieValueIterator(depth - 1, current_key, at_end, up(parent))
    end
end

function is_end(it::TrieValueIterator{K}) where {K}
    return it.is_end

    #=
    at_end = true
    depth = it.depth

    parent = it.trie_iterator
    while true
        if !is_end(next(parent))
            at_end = false
            break
        end

        if is_root(parent)
            break
        end

        parent = up(parent)
    end

    println("is at_end?? ", at_end)

    return at_end
    =#
end


# ==============================================================================

function Trie(items)::Trie{Any{}}
    result = Trie{Any}()
    for item in items
        insert!(result, item)
    end
    return result
end

end
