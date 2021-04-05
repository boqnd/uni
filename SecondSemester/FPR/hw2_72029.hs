main :: IO ()
main = do
  print ("First task")
  print ("----------")
  print (countRats ")1)1)1)1 P")
  print (countRats "P 1( 1( )1 1(")
  print (countRats " P1(1( )11(")
  print (countRats ")1)1)1)1P)1)11(")
  print (countRats "1()1)1)11(1()1)1P)11()1)1)11(1(1(1(")
  print()
  print ("Second task")
  print ("-----------")
  print ((josephus [1,2,3,4,5,6,7]) 3)
  print ((josephus [1,2,3,4,5,6,7]) (-1))
  print ((josephus [1,2,3,4,5,6,7,8,9,10]) 1)
  print ((josephus [1,2,3,4,5,6,7,8,9,10]) 2)
  print ((josephus "fpFMIsu") 4)


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