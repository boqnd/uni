main :: IO ()
main = do 
  print (persistence 39)
  print (persistence 999)
  print (persistence 126)
  print (persistence 4)


prodDigits :: Int -> Int
prodDigits x = helper x 1
  where
    helper x result
      | x == 0 = result
      | otherwise = helper (x `div` 10) (x `mod` 10 * result) 


createList :: Int -> [Int]
createList x = if x < 10 then [x] else helper x []
  where
    helper curr result
      | curr < 10 = (result)
      | otherwise = helper (prodDigits curr) (result ++ [prodDigits curr])

persistence :: Int -> (Int, [Int])
persistence x = (length (createList x), createList x)


