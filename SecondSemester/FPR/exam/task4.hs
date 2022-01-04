main :: IO ()
main = do
  print (deepestNodesSum odd t1)

data BTree = Empty | Node Int BTree BTree

t1 :: BTree
t1 = Node 1 (Node 2 (Node 4 (Node 7 Empty Empty)
                            Empty)
                    (Node 5 Empty Empty))
            (Node 3 Empty
                   (Node 6 Empty
                           (Node 8 Empty Empty)))

deepestNodesSum :: (Int -> Bool) -> BTree -> Int
deepestNodesSum f tree = sum [x | x <- (getDeepestNodes tree), f x]

getDeepestNodes :: BTree -> [Int]
getDeepestNodes tree = helper tree (height tree)
  where
    helper Empty h = []
    helper (Node x lt rt) h
      | h == 0 = [x]
      | otherwise = (helper lt (h-1)) ++ (helper rt (h-1))

height :: BTree -> Int
height (Node x Empty Empty) = 0
height (Node x lt Empty) = 1 + (height lt)
height (Node x Empty rt) = 1 + (height rt)
height (Node x lt rt) = 1 + (max (height lt) (height rt))