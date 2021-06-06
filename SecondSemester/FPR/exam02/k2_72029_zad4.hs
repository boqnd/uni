main :: IO ()
main = do 
  print (findJudge 2 [(1, 2)])
  print (findJudge 3 [(1, 3), (2, 3)])
  print (findJudge 3 [(1, 3), (2, 3), (3,1)])
  print (findJudge 3 [(1, 2), (2, 3)])
  print (findJudge 4 [(1, 3), (1, 4), (2, 3), (2, 4), (4, 3)])

findJudge :: Int -> [(Int, Int)] -> Int
findJudge n xs = if (null [x | (x, l) <- [(x, length [b | (a, b) <- xs, b == x]) | x <- [j | j <- [1..n], not (elem j [a | (a, b) <- xs])]], l == (n-1)]) then (-1) else head [x | (x, l) <- [(x, length [b | (a, b) <- xs, b == x]) | x <- [j | j <- [1..n], not (elem j [a | (a, b) <- xs])]], l == (n-1)]