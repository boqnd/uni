main :: IO ()
main = do 
  print (mapNested (*3) nl1)
  print (mapNested (take 2 . show) (List [Elem 15, List [Elem 200, List [Elem 351.52, Elem 463.12], Elem 5]]))
  print (mapNested (*3) (Elem 1))


data NestedList a = Elem a | List [NestedList a] deriving Show

nl1 :: NestedList Int
nl1 = List [Elem 1, List [Elem 2, List [Elem 3, Elem 4], Elem 5]]

mapNested :: (a -> b) -> (NestedList a) -> (NestedList b)
mapNested f (Elem x) = Elem (f x)
mapNested f (List ns) = List [(mapNested f elem) | elem <- ns] 