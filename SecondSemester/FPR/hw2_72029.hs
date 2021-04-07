main :: IO ()
main = do
  -- print ("First task")
  -- print ("----------")
  -- print (countRats ")1)1)1)1 P")
  -- print (countRats "P 1( 1( )1 1(")
  -- print (countRats " P1(1( )11(")
  -- print (countRats ")1)1)1)1P)1)11(")
  -- print (countRats "1()1)1)11(1()1)1P)11()1)1)11(1(1(1(")
  -- print()
  -- print ("Second task")
  -- print ("-----------")
  print ((josephusAnanase [1,2,3,4,5,6,7]) 3)
  print ((josephusAnanase [1,2,3,4,5,6,7]) (-1))
  print ((josephusAnanase [1,2,3,4,5,6,7,8,9,10]) 1)
  print ((josephusAnanase [1,2,3,4,5,6,7,8,9,10]) 2)
  print ((josephusAnanase "fpFMIsu") 4)
  -- josephusAnanase
  -- print $ countRats' "1()1)1)11(1()1)1P)11()1)1)11(1(1(1("
  --print(countrats "2$") error "schupi se"
--countRats ")1)1)1)1 P" → 0 -- всички плъхове се движат към ловеца
--countRats "P 1( 1( )1 1(" → 1

countRats' :: String -> Int
countRats' str = helper str False
  where
    helper :: String -> Bool -> Int
    helper str hunterFound
      | null str = 0
      | hunterFound == False && head str == '(' = (helper (tail str) hunterFound) + 1
      | hunterFound == False && head str == 'P' = helper (tail str) True
      | hunterFound == False = helper (tail str) hunterFound
      | hunterFound == True && head str == ')' = (helper (tail str) hunterFound) + 1
      | hunterFound == True = helper (tail str) hunterFound


countRats :: String -> Int
countRats [] = 0
countRats legend = helper legend False
  where
    helper :: String -> Bool -> Int
    helper [] _ = 0  
    helper ('P':xs) False = helper xs True
    helper ('(':xs) False = 1 + helper xs False
    helper (x:xs) False = helper xs False
    helper (')':xs) True = 1 + helper xs True
    helper (x:xs) True = helper xs True


josephus :: [a] -> (Int -> [a])
josephus xs = helper
  where
    helper m = result xs []
      where
        result :: [a] -> [a] -> [a]
        result xs res
          | m <= 0 = []
          | null xs = res
          | m `mod` (length xs) == 0 = result (removeElement xs (length xs)) (res ++ [(takeElement xs (length xs))])
          | m > (length xs) = result (removeElement xs (m `mod` (length xs))) (res ++ [(takeElement xs (m `mod` (length xs)))])
          | otherwise = result (removeElement xs m) (res ++ [(takeElement xs m)])
            where
              takeElement [x] _ = x
              takeElement (x:xs) 1 = x
              takeElement (x:xs) n = takeElement xs (n-1)
              removeElement [x] _ = []
              removeElement xs n = drop n xs ++ take (n-1) xs


josephusAnanase ::Eq a => [a] -> (Int -> [a])
josephusAnanase xs = \ x ->  helper x 1 xs []
    where
        helper k n (x:xs) answer
            |null xs = (answer ++ [x]) 
            |n `mod` k == 0 = helper k (n + 1) xs (answer ++ [x])
            |otherwise = helper k (n + 1) (xs ++ [x]) answer


josephusAnanase' :: Eq a => [a] -> (Int -> [a])
josephusAnanase' xs = \ x -> helper x 1 xs []
    where
        helper k n (x:xs) answer
            |null xs = (reverse ([x] ++ answer))
            |n `mod` k == 0 = helper k (n + 1) xs (reverse ([x] ++ answer))
            |otherwise = helper k (n + 1) (xs ++ [x]) answer