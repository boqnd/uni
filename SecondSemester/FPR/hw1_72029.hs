main :: IO ()
main = do
  firstTaskA
  firstTaskB
  secondTask
  

--Functions for printing the examples
firstTaskA :: IO ()
firstTaskA = do
  print ("--------------------------")
  print ("1. a)")
  print ("safePrimesCount 20 100 -> " ++ show (safePrimesCount 20 100))
  print ("safePrimesCount  1 983 -> " ++ show (safePrimesCount 1 983))
  print ("--------------------------")

firstTaskB :: IO ()
firstTaskB = do
  print ("--------------------------")
  print ("1. b)")
  print ("specialSum   3 20 -> " ++ show (specialSum 3 20))
  --It is too slow...
  --print ("specialSum   5 31 -> " ++ show (specialSum 5 31))
  print ("--------------------------")

secondTask :: IO ()
secondTask = do
  print ("--------------------------")
  print ("2.")
  print ("validate 1714          -> " ++ show (validate 1714))
  print ("validate 12345         -> " ++ show (validate 12345))
  print ("validate 891           -> " ++ show (validate 891))
  print ("validate 123           -> " ++ show (validate 123))
  print ("validate 2121          -> " ++ show (validate 2121))
  print ("validate 4736778291034 -> " ++ show (validate 4736778291034))
  print ("validate 4485756008412 -> " ++ show (validate 4485756008412))
  print ("validate 4485756008422 -> " ++ show (validate 4485756008422))
  print ("validate 4214154976719 -> " ++ show (validate 4214154976719))
  print ("--------------------------")




--FIRST TASK A
--Check if number is prime (made it outside function because it is used multiple times)
isPrime :: Int -> Bool
isPrime k = if k > 1 then null [ x | x <- [2..k - 1], k `mod` x == 0] else False

isSafePrime :: Int -> Bool
isSafePrime x = isPrime x && x `mod` 2 == 1 && isPrime ((x-1) `div` 2)

safePrimesCount :: Int -> Int -> Int
safePrimesCount a b
  | a > b = 0
  | isSafePrime a = 1 + safePrimesCount (a+1) b
  | otherwise = safePrimesCount (a+1) b

--shorter solution
safePrimesCount' :: Int -> Int -> Int
safePrimesCount' a b = length [x | x <- [a..b], isSafePrime x]



--FIRST TASK B
--Tuk izpolzvam funkcii koito ne sa prepodavani, nadyavam se tova ne e problem, i se vijda, 
--  che moga da reshavam zadachite.  :)
specialSum :: Int -> Int -> Int
specialSum k m = sumList(take k [x | x <- [(m+1), (m+2)..], isSpecial x])
  where
    sumList :: [Int] -> Int
    sumList [] = 0
    sumList (x:xs) = x + sumList xs
    isSpecial :: Int -> Bool
    isSpecial x = isPrimePowerOfTwo (x+1)
      where
        isPrimePowerOfTwo x = helper x 0
          where
            helper x n
              | 2^n == x && isPrime n = True
              | 2^n > x = False
              | otherwise = helper x (n+1)


--SECOND TASK
validate :: Int -> Bool
validate num = sumList (listOfDigitsWithDoubledEveryOther num) `mod` 10 == 0
  where
    sumList :: [Int] -> Int
    sumList [] = 0
    sumList (x:xs) = x + sumList xs
    listOfDigitsWithDoubledEveryOther :: Int -> [Int]
    listOfDigitsWithDoubledEveryOther n = helper n 1
      where
        helper n counter
          | n == 0 = []
          | counter `mod` 2 == 0 = helper (n `div` 10) (counter+1) ++ [sumDigits ((n `mod` 10) * 2)]
          | otherwise = helper (n `div` 10) (counter+1) ++ [n `mod` 10]
          where
            sumDigits n
              | n == 0 = 0
              | otherwise = (n `mod` 10) + sumDigits (n `div` 10)