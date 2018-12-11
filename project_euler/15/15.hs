triangle :: Int -> Int
triangle 0 = 0
triangle n = n + (triangle (n - 1))

fnSum' :: Int -> (Int -> Int) -> Int -> Int -> Int
fnSum' a f x y =
    case x < y of
        True    -> fnSum' (a * (f x)) f (x + 1) y
        _       -> a

fnSum :: (Int -> Int) -> Int -> Int -> Int
fnSum = fnSum' 1

main = do
    print $ sum (map (\x -> 20^x - (x-1)) [1..20])
