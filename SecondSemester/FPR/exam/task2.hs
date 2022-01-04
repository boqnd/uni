main :: IO ()
main = do
  print ((speak "gate") 't')

speak :: String -> (Char -> String)
speak s = speak'
  where
    speak' :: Char -> String
    speak' c = (foldl helper [(head s)] (tail s))
      where
        helper :: String -> Char -> String
        helper a b = a ++ [b]


