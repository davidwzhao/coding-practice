myReverse :: [a] -> [a]
myReverse = foldl (\x a -> a:x) []

equalLists :: Eq a => [a] -> [a] -> Bool
equalLists [] [] = True
equalLists (x:xs) [] = False
equalLists [] (x:xs) = False
equalLists (x:xs) (y:ys) = x == y && equalLists xs ys

isPalindrome :: Eq a => [a] -> Bool
isPalindrome l = equalLists l (myReverse l)

isPalindrome' :: Eq a => [a] -> Bool
isPalindrome' l = l == (myReverse l)
