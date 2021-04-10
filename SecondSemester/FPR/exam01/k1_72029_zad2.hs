main :: IO ()
main = do 
  --print ((kthMaxMin [-1,0,-1,0,-2,3,1,-1]) 3)
  --print (removeElement 3 [-1,0,-1,0,-2,3,1,-1])
  --print (removeElement (findMax [1]) [1])
  --print (sort [-1,-4,-3,-5,-6])
  print ((kthMaxMin [-1]) 1)
  print ((kthMaxMin [-1,-5,-6,-6,-6,-6]) 2)
  print ((kthMaxMin [1,2,3,4,-5,6,7,-2,-1,0]) 2)
  print ((kthMaxMin [-1,0,-1,0,-2,3,1,-1]) 3)


kthMaxMin :: [Int] -> (Int -> Int)
kthMaxMin xs = kthMaxMin'
  where
    kthMaxMin' k = if k > length (removeDuplcates (getNegativeNumbers xs)) then error "No such number" else head (drop (k-1) (sort (removeDuplcates (getNegativeNumbers xs))))

getNegativeNumbers :: [Int] -> [Int]
getNegativeNumbers xs = helper xs []
  where
    helper [] rs = rs
    helper (x:xs) rs = if x < 0 then helper xs (x:rs) else helper xs rs

removeDuplcates :: [Int] -> [Int]
removeDuplcates xs = helper xs []
  where
    helper [] result = result
    helper (x:xs) result = if contains x result then helper xs result else helper xs (x:result)
      where
        contains _ [] = False
        contains n (x:xs) = if x==n then True else contains n xs

sort :: [Int] -> [Int]
sort xs = helper xs []
  where
    helper [] result = result
    helper xs result = helper (removeElement (findMax xs) xs) (result ++ [findMax xs])


findMax :: [Int] -> Int
findMax xs = helper xs (-10000000)
  where
    helper [] result = result
    helper (x:xs) result = if x > result then helper xs x else helper xs result

removeElement :: Int -> [Int] -> [Int]
removeElement n xs = helper n xs []
  where
    helper n [] result = result
    helper n (x:xs) result = if x == n then (result ++ xs) else helper n xs (result ++ [x])