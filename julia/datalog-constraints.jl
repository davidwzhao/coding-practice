@time Datalog.interpret(
Datalog.EvalIterator[Datalog.BindScalar(false, Symbol("semi#1"), DelveTypes.WrappedType(Int64), Datalog.Actions(Tuple{Symbol,Symbol}[], Tuple{Symbol,Symbol}[])), Datalog.HeadUpdate(Datalog.Clause(Datalog.Atom[Datalog.Atom(Symbol("##delve-query-action##1450#a#0#1451"), [Symbol("semi#1")]), Datalog.Atom(Symbol("a\$1"), [Symbol("semi#1")])]
, Datalog.And(Datalog.Formula[Datalog.Atom(Datalog.Lit(Tuple{DelveTypes.WrappedType}[(DelveTypes.WrappedType(Int64),)]), [Symbol("semi#1")])])), Dict{Symbol,SortedSet}(Symbol("a\$1") => SortedSet(Any[],
Base.Order.ForwardOrdering()),Symbol("##delve-query-action##1450#a#0#1451") => SortedSet(Any[],
Base.Order.ForwardOrdering())))]
, Dict{Symbol,Any}()
)

@time Datalog.interpret(
Datalog.EvalIterator[Datalog.HeadUpdate(Datalog.Clause(Datalog.Atom[Datalog.Atom(Symbol("##delve-query-action##1450#a#0#1451"), [Symbol("semi#1")]), Datalog.Atom(Symbol("a\$1"), [Symbol("semi#1")])], Datalog.And(Datalog.Formula[Datalog.Atom(Datalog.Lit(Tuple{DelveTypes.WrappedType}[(DelveTypes.WrappedType(Int64),)]), [Symbol("semi#1")])]
)), Dict{Symbol,SortedSet}(Symbol("a\$1") => SortedSet(Any[],
Base.Order.ForwardOrdering()),Symbol("##delve-query-action##1450#a#0#1451") => SortedSet(Any[],
Base.Order.ForwardOrdering())))]
, Dict{Symbol,Any}(Symbol("semi#1") => DelveTypes.WrappedType(Int64))
)

@time Datalog.interpret(
Datalog.EvalIterator[Datalog.BindScalar(false, Symbol("x#0"), DelveTypes.WrappedType(Int64), Datalog.Actions(Tuple{Symbol,Symbol}[], Tuple{Symbol,Symbol}[])), Datalog.HeadUpdate(Datalog.Clause(Datalog.Atom[Datalog.Atom(Symbol("##delve-query-action##1450#constraint#0#1452"), [Symbol("x#0")]), Datalog.Atom(Symbol("delve-query-action##1450#constraint#0\$0"), Symbol[])], Datalog.And(Datalog.Formula[Datalog.Atom(Datalog.Lit(Set(Array{DBType,1}[[DelveTypes.WrappedType(Int64)]])), [Symbol("x#0")])])), Dict{Symbol,SortedSet}(Symbol("delve-query-action##1450#constraint#0\$0") => SortedSet(Any[],
Base.Order.ForwardOrdering()),Symbol("##delve-query-action##1450#constraint#0#1452") => SortedSet(Any[],
Base.Order.ForwardOrdering())))]
, Dict{Symbol,Any}()
)

@time Datalog.interpret(
Datalog.EvalIterator[Datalog.HeadUpdate(Datalog.Clause(Datalog.Atom[Datalog.Atom(Symbol("##delve-query-action##1450#constraint#0#1452"), [Symbol("x#0")]), Datalog.Atom(Symbol("delve-query-action##1450#constraint#0\$0"), Symbol[])], Datalog.And(Datalog.Formula[Datalog.Atom(Datalog.Lit(Set(Array{DBType,1}[[DelveTypes.WrappedType(Int64)]]))
, [Symbol("x#0")])])), Dict{Symbol,SortedSet}(Symbol("delve-query-action##1450#constraint#0\$0") => SortedSet(Any[],
Base.Order.ForwardOrdering()),Symbol("##delve-query-action##1450#constraint#0#1452") => SortedSet(Any[],
Base.Order.ForwardOrdering())))]
, Dict{Symbol,Any}(Symbol("x#0") => DelveTypes.WrappedType(Int64))
)

@time Datalog.interpret(
Datalog.EvalIterator[Datalog.BindScalar(false, Symbol("comma#0"), DelveTypes.WrappedType(DelveTypes.Empty), Datalog.Actions(Tuple{Symbol,Symbol}[], Tuple{Symbol,Symbol}[])), Datalog.HeadUpdate(Datalog.Clause(Datalog.Atom[Datalog.Atom(Symbol("##output_delve-query-action##1450#constraint#0#1453"), [Symbol("comma#0")]), Datalog.Atom(Symbol(
"output\$1"), [Symbol("comma#0")])], Datalog.And(Datalog.Formula[Datalog.Atom(Datalog.Lit(Tuple{DelveTypes.WrappedType}[(DelveTypes.WrappedType(DelveTypes.Empty),)]), [Symbol("comma#0")])])), Dict{Symbol,SortedSet}(Symbol("##output_delve-query-action##1450#constraint#0#1453") => SortedSet(Any[],
Base.Order.ForwardOrdering()),Symbol("output\$1") => SortedSet(Any[],
Base.Order.ForwardOrdering())))]
, Dict{Symbol,Any}()
)

@time Datalog.interpret(
Datalog.EvalIterator[Datalog.HeadUpdate(Datalog.Clause(Datalog.Atom[Datalog.Atom(Symbol("##output_delve-query-action##1450#constraint#0#1453"), [Symbol("comma#0")]), Datalog.Atom(Symbol("output\$1"), [Symbol("comma#0")])], Datalog.And(Datalog.Formula[Datalog.Atom(Datalog.Lit(Tuple{DelveTypes.WrappedType}[(DelveTypes.WrappedType(DelveTypes.Empty),)]), [Symbol("comma#0")])])), Dict{Symbol,SortedSet}(Symbol("##output_delve-query-action##1450#constraint#0#1453") => SortedSet(Any[],
Base.Order.ForwardOrdering()),Symbol("output\$1") => SortedSet(Any[],
Base.Order.ForwardOrdering())))]
, Dict{Symbol,Any}(Symbol("comma#0") => DelveTypes.WrappedType(DelveTypes.Empty))
)

@time Datalog.interpret(
Datalog.EvalIterator[Datalog.HeadUpdate(Datalog.Clause(Datalog.Atom[Datalog.Atom(Symbol("##abort_delve-query-action##1450#constraint#0#1454"), Symbol[]), Datalog.Atom(Symbol("abort\$0"), Symbol[])], Datalog.And(Datalog.Formula[])), Dict{Symbol,SortedSet}(Symbol("##abort_delve-query-action##1450#constraint#0#1454") => SortedSet(Any[],
Base.Order.ForwardOrdering()),Symbol("abort\$0") => SortedSet(Any[],
Base.Order.ForwardOrdering())))]
, Dict{Symbol,Any}()
)

@time Datalog.interpret(
Datalog.EvalIterator[Datalog.BindScalar(false, :ic_name, DelveTypes.WrappedType(DelveTypes.Empty), Datalog.Actions(Tuple{Symbol,Symbol}[], Tuple{Symbol,Symbol}[])), Datalog.HeadUpdate(Datalog.Clause(Datalog.Atom[Datalog.Atom(Symbol("##ic_violation_delve-query-action##1450#constraint#0#1455"), [:ic_name]), Datalog.Atom(Symbol("##ic_violation##\$1"), [:ic_name])], Datalog.And(Datalog.Formula[Datalog.Atom(Datalog.Lit(Tuple{DelveTypes.WrappedType}[(DelveTypes.WrappedType(DelveTypes.Empty),)]), [:ic_name])])), Dict{Symbol,SortedSet}(Symbol("##ic_violation##\$1") => SortedSet(Any[],
Base.Order.ForwardOrdering()),Symbol("##ic_violation_delve-query-action##1450#constraint#0#1455") => SortedSet(Any[],
Base.Order.ForwardOrdering())))]
, Dict{Symbol,Any}()
)

@time Datalog.interpret(
Datalog.EvalIterator[Datalog.HeadUpdate(Datalog.Clause(Datalog.Atom[Datalog.Atom(Symbol("##ic_violation_delve-query-action##1450#constraint#0#1455"), [:ic_name]), Datalog.Atom(Symbol("##ic_violation##\$1"), [:ic_name])], Datalog.And(Datalog.Formula[Datalog.Atom(Datalog.Lit(Tuple{DelveTypes.WrappedType}[(DelveTypes.WrappedType(DelveTypes.
Empty),)]), [:ic_name])])), Dict{Symbol,SortedSet}(Symbol("##ic_violation##\$1") => SortedSet(Any[],
Base.Order.ForwardOrdering()),Symbol("##ic_violation_delve-query-action##1450#constraint#0#1455") => SortedSet(Any[],
Base.Order.ForwardOrdering())))]
, Dict{Symbol,Any}(:ic_name => DelveTypes.WrappedType(DelveTypes.Empty))
)
