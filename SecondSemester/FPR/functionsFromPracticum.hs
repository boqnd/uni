main :: IO ()
main = do
  print (levelsum bt1 0)

--Week 13
listOfIndexes :: Int -> [Int] -> [Int]
listOfIndexes n xs = [ i | (x, i) <- (zip xs [0..]), x == n] 

averageFunction :: [(Double -> Double)] -> (Double -> Double)
averageFunction fs = (\ x -> (sum (xs x)) / fromIntegral (length (xs x)))
  where
    xs x = [f x | f <- fs]

data BTree = Empty | BTree Int BTree BTree

bt1 :: BTree
bt1 = BTree 5 (BTree 2 Empty (BTree 3 Empty Empty) ) (BTree 6 Empty Empty)

levelsum :: BTree -> Int -> Int
levelsum t k = sum [ n | (n, level) <- (indexed t 0), level == k]
  where
    indexed Empty _ = []
    indexed (BTree n lt rt) level = (n, level) : ((indexed lt (level+1)) ++ (indexed rt (level+1)))


--Week 7
primesInRange :: Integer -> Integer -> [Integer]
primesInRange a b = [x | x <- [a..b], isPrime x]
  where
    isPrime b = [x | x<-[2..b], b `mod` x == 0] == [b]

prodSumDiv :: [Integer] -> Integer -> Integer
prodSumDiv ls k = product [x | x <- ls, (sumDivisors x) `mod` k == 0]
  where 
    sumDivisors x = sum [a | a <- [1..x], x `mod` a == 0] 

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (x:y:ls) = if x < y then isSorted(y:ls) else False

insert :: Int -> [Int] -> [Int]
insert x xs 
  | null xs = [x]
  | x < head xs = (x:xs)
  | x > last xs = (xs ++ [x])
  | otherwise = [n | n <- [head xs..last xs], elem n xs || n == x]

insert' :: Int -> [Int] -> [Int]
insert' k [] = [k] 
insert' k (x:xs) = if k < x then k:insert' x xs else x:insert' k xs

--Week 6
mIdentity :: a -> a
mIdentity x = x

myCompose :: (a -> b) -> (c -> a) -> (c -> b)
myCompose f g = \ x -> f (g x)

myNegate :: (a -> Bool) -> (a -> Bool)
myNegate p = myCompose not p

difference :: Num b => (a -> b) -> a -> a -> b
difference f a b = f b - f a

f = (\ x -> 2*x)

derivative :: (Double -> Double) -> Double -> (Double -> Double)
derivative f eps = \ x -> (f(x+eps) - f(x))/eps

derivative2 :: (Double -> Double) -> Double -> (Double -> Double)
derivative2 f eps = \ x -> derivative (derivative f eps) eps x

-- derivativeN :: (Double -> Double) -> Int -> Double -> (Double -> Double)
-- derivativeN f 0 _ = f
-- derivativeN f n eps = derivative (derivative f (n-1) eps) eps

--Week 5
divisors :: Int -> [Int]
divisors n = [x | x <- [1..n], n `mod` x == 0]

isImage :: [Int] -> [Int] -> Bool
isImage as bs = as == [d + (head as - head bs) | d <- bs]

chunksOf :: Num a => Int -> [a] -> [[a]]
chunksOf k xs
  | null xs = []
  | otherwise =  (take k xs) : chunksOf k (drop k xs)

--ananase
--
-- numToList :: Int -> [Int]
-- numToList 0 = []
-- numToList x = numToList (x `div` 10) ++ [x `mod` 10]

-- isAscending :: Int -> Bool 
-- isAscending a = numToList a == listSort (numToList a)
--   where 
--     listSort:: [Int] -> [Int]
--     listSort [] = []
--     listSort (x:xs) = listSort smaller ++ [x] ++ listSort bigger
--       where
--       smaller = [s | s <- xs, s <= x]
--

--Week 4
countMembers :: [Int] -> Int
countMembers xs = if (null xs) then 0 else 1 + countMembers(tail xs)

arrSum :: [Int] -> Int
arrSum xs = if (null xs) then 0 else ((head xs) + arrSum(tail xs))

contains :: Int -> [Int] -> Bool
contains n xs
  | null xs = False
  | head xs == n = True
  | otherwise = contains n (tail xs)

removeFirstX :: [Int] -> Int -> [Int]
removeFirstX xs n = helper xs []
  where
    helper xs result
      | null xs = result
      | head xs /= n = helper (tail xs) (result ++ [head xs])
      | otherwise = (result ++ (tail xs))

removeAllX' :: [Int] -> Int -> [Int]
removeAllX' xs n = [x | x <- xs, x /= n]


removeAllX :: [Int] -> Int -> [Int]
removeAllX xs n = helper xs []
  where
    helper xs result
      | null xs = result
      | head xs /= n = helper (tail xs) (result ++ [head xs])
      | otherwise = if null (tail xs) then helper [] result else (helper (tail xs) (result ++ [(head (tail xs))]))

incrementAllBy :: [Int] -> Int -> [Int]
incrementAllBy xs n
  | null (tail xs) = [(head xs) + n]
  | otherwise = ((head xs) + n) : incrementAllBy (tail xs) n


--Week 3
isPalindrome :: Integer -> Bool
isPalindrome n = n == reverseNumber n

countPalindromes :: Integer -> Integer -> Integer
countPalindromes a b
  | a > b = 0
  | isPalindrome a = 1 + countPalindromes (a + 1) b
  | otherwise = countPalindromes (a + 1) b

pow :: Double -> Integer -> Double
pow x n
  | n == 0 = 1
  | otherwise = x * pow x (n-1)

isPrime :: Integer -> Bool
isPrime n
  | n == 1 = False
  | otherwise = helper n (n - 1)
    where 
      helper n curr 
        | curr == 1 = True
        | (n `mod` curr) == 0 = False
        | otherwise = helper n (curr - 1)

isAscending :: Integer -> Bool
isAscending n 
  | n == 0 = True
  | n < 0 = False
  | ((n `div` 10) `mod` 10) > (n `mod` 10) = False
  | otherwise = isAscending (n `div` 10)

countOccurences :: Integer -> Integer -> Integer
countOccurences number n
  | number == 0 = 0
  | (number `mod` 10) == n = 1 + countOccurences (number `div` 10) n
  | otherwise = countOccurences (number - 1) n

isPerfectNumber :: Integer -> Bool
isPerfectNumber n = sumD (n-1) == n
  where
    sumD curr
      | curr == 1 = 1
      | n `mod` curr == 0 = curr + sumD (curr - 1)
      | otherwise = sumD (curr - 1)

sumPrimeDivisors :: Integer -> Integer
sumPrimeDivisors n = helper (n-1)
  where
    helper d
      | d <= 1 = 0
      | (((n `mod` d) == 0) && (isPrime d)) = d + helper (d-1)
      | otherwise = helper (d-1)



--Week 2
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



--Week 1
fibIter :: Int -> Int
fibIter n = helper 1 1 n

helper :: Int -> Int -> Int -> Int
helper a b n = do
  if n < 3 then b else helper b (a+b) (n-1)

myMin :: Int -> Int -> Int
myMin a b = if a < b then a else b

inside :: Int -> Int -> Int -> Int
inside x a b = if x >= a && x <= b then 1 else 0