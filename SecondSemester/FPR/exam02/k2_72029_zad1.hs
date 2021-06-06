main :: IO ()
main = do 
  print ((getIndices [2, 7, 11, 15]) 9)
  print ((getIndices [3, 2, 4]) 6)
  print ((getIndices [3, 3]) 6)


getIndices :: [Int] -> (Int -> (Int, Int))
getIndices xs = (\n -> head ( head [x | x <- [[(i, i_) | (x_,i_) <- zip xs [0..], not (i == i_), (x+x_) == n] | (x,i) <- zip xs [0..]], not (null x)]))