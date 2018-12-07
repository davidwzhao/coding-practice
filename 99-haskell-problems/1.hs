myLast :: [a] -> a
myLast [] = error "bad"
myLast [x] = x
myLast (x:xs) = myLast xs

myLast' :: [a] -> a
myLast' = foldr1 (const id)
