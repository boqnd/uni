main :: IO ()
main = do
  print(reverseNumber 123)

reverseNumber :: Integer -> Integer
reverseNumber n = reverseNumberHelper n 0

reverseNumberHelper :: Integer -> Integer -> Integer
reverseNumberHelper n res
  | n == 0 = res
  | otherwise = reverseNumberHelper (n `div` 10) (res*10 + (n `mod` 10))



sumDigitsIter :: Integer -> Integer
sumDigitsIter n = sumDigitsIterHelper n 0

sumDigitsIterHelper :: Integer -> Integer -> Integer
sumDigitsIterHelper n sum
  | n == 0 = sum
  | otherwise = sumDigitsIterHelper (n `div` 10) (sum + (n `mod` 10))


sumDigitsRec :: Integer -> Integer
sumDigitsRec n
  | n < 10 = n
  | otherwise = (n `mod` 10) + sumDigitsRec(n `div` 10)

countDigits :: Integer -> Integer
countDigits n = countDigitsHelper n 0

countDigitsHelper :: Integer -> Integer -> Integer
countDigitsHelper n counter
  | n == 0 = counter 
  | otherwise = countDigitsHelper (n `div` 10) (counter+1)

fibIter :: Int -> Int
fibIter n = helper 1 1 n

helper :: Int -> Int -> Int -> Int
helper a b n = do
  if n < 3 then b else helper b (a+b) (n-1)

myMin :: Int -> Int -> Int
myMin a b = if a < b then a else b

inside :: Int -> Int -> Int -> Int
inside x a b = if x >= a && x <= b then 1 else 0



