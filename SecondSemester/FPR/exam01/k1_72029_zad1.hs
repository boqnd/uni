main :: IO ()
main = do 
  print (sumOfEvenly 1 10)
  print (sumOfEvenly 5 20)


sumOfEvenly :: Int -> Int -> Int
sumOfEvenly a b = sum [x | x <- [a..b], isEvenly x]
  where
    isEvenly x = length [d | d <- [1..x], x `mod` d == 0] `mod` 2 == 0