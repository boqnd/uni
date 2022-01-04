main :: IO ()
main = do
  print (cook [ApplePie, ApplePie, Burger, Chicken, Chicken, ApplePie])

data Meal = ApplePie | Burger | Chicken deriving (Eq, Show)
data Wether = Sunny | Rainy deriving (Eq, Show)

cook :: [Meal] -> [Wether]
cook ms
  | (size ms) > 1 = if ((head ms) == (head (tail ms))) then [Sunny]++(cook (tail ms)) else [Rainy]++(cook (tail ms))
  | otherwise = []

size :: [Meal] -> Int
size ms
  | null ms = 0
  | otherwise = 1 + (size (tail ms))