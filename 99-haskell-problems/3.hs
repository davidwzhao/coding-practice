elementAt :: [a] -> Int -> a
elementAt [] _ = error "Index out of bounds"
elementAt (x : xs) 1 = x
elementAt (x : xs) n = elementAt xs (n - 1)

elementAt' :: [a] -> Int -> a
elementAt' xs n
 | length xs < n = error "Index out of bounds"
 | otherwise = last $ take n xs
