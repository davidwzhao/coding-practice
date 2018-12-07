myLast :: [a] -> a
myLast [] = error "bad"
myLast [x] = x
myLast (x:xs) = myLast xs

myInit :: [a] -> [a]
myInit [] = []
myInit [x] = []
myInit (x : xs) = x : myInit xs

myReverse :: [a] -> [a]
myReverse [] = []
myReverse xs = myLast xs : (myReverse $ myInit xs)

myReverse' :: [a] -> [a]
myReverse' [] = []
myReverse' xs = last xs : (myReverse' $ init xs)

myReverse''' :: [a] -> [a]
myReverse''' = foldl (\a x -> x:a) []
