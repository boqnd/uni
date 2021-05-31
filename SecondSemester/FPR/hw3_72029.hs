import Data.List
import Data.Char

main :: IO ()
main = do
  print (degr t1 7)

data NTree a = Nil | Node a [NTree a] deriving (Show, Eq)

tr :: NTree Int
tr = Node 8 [Node 4 [],Node 5 [],Node 6 []]

tree :: NTree Int
tree = Node 8 [
  Node 7 [
    Node 4 [],
    Node 5 []],
  Node 6 [
    Node 10 [],
    Node 15 [],
    Node 13 []],
  Node 18 []]

t1 :: NTree Int
t1 = Node 8 [Node 7 [Node 4 [Nil], Node 5 [Nil]],Node 6 [Node 10 [Nil], Node 15[Nil],Node 13[Nil]], Node 18 [Nil]]

degr :: (Eq a) => NTree a -> a -> Int 
degr (Node n ts) x = if (n == x) then countKids (Node n ts) else (1 + (length (degrHelper (Node n ts))))
        where
            degrHelper Nil = []
            degrHelper (Node k tsk) = if (k == x) then [n | (Node n tsk) <- tsk] else concatMap degrHelper tsk

searchKids :: (Eq a) => NTree a -> a -> NTree a
searchKids tree x = if (searchKidsHelper tree x) then tree else Nil
  where
    searchKidsHelper :: (Eq a) => NTree a -> a -> Bool
    searchKidsHelper Nil _ = False
    searchKidsHelper (Node _ []) _ = False
    searchKidsHelper (Node n ((Node nk ks):ts)) x = if (nk == x) then True else searchKidsHelper (Node n ts) x

countKids :: (Eq a) => NTree a -> Int
countKids Nil = 0
countKids (Node _ []) = 0
countKids (Node n (t:ts)) = 1 + countKids (Node n ts)

type Name = String
type Title = String
type Year = Int
type Gender = Char
type Length = Int

data Movie = Movie Title Year Length deriving Show
data MovieStar = MovieStar Name Gender deriving Show
data StarsIn = StarsIn Name Title deriving Show
type MovieDB = ([Movie], [MovieStar], [StarsIn])

movies :: [Movie]
movies = [Movie "The Man Who Wasn't There" 2001 116,
          Movie "Logan's run" 1976 120,
          Movie "Star Wars" 1977 124,
          Movie "Empire Strikes Back" 1980 111,
          Movie "Star Trek" 1979 132,
          Movie "Star Trek: Nemesis" 2002 116,
          Movie "Terms of Endearment" 1983 132,
          Movie "The Usual Suspects" 1995 106,
          Movie "Gone With the Wind" 1938 238,
          Movie "The Fellowship of the Ring" 2001 178]

stars :: [MovieStar]
stars = [MovieStar "Jane Fonda" 'F',
         MovieStar "Alec Baldwin" 'M',
         MovieStar "Kim Basinger" 'F',
         MovieStar "Harrison Ford" 'M',
         MovieStar "Debra Winger" 'F',
         MovieStar "Jack Nicholson" 'M',
         MovieStar "Sandra Bullock" 'F',
         MovieStar "Orlando Bloom" 'M',
         MovieStar "Cate Blanchett" 'F',
         MovieStar "Liv Tyler" 'F',
         MovieStar "Billy Bob Thornton" 'M',
         MovieStar "Scarlett Johansson" 'F']

starsIn :: [StarsIn]
starsIn = [StarsIn "Kim Basinger" "Star Wars",
  StarsIn "Alec Baldwin" "Star Wars",
  StarsIn "Harrison Ford" "Star Wars",
  StarsIn "Harrison Ford" "Empire Strikes Back",
  StarsIn "Jack Nicholson" "The Usual Suspects",
  StarsIn "Jane Fonda" "Terms of Endearment",
  StarsIn "Jack Nicholson" "Terms of Endearment",
  StarsIn "Sandra Bulloc" "The Usual Suspects",
  StarsIn "Billy Bob Thornton" "The Man Who Wasn't There",
  StarsIn "Scarlett Johansson" "The Man Who Wasn't There",
  StarsIn "Orlando Bloom" "The Fellowship of the Ring",
  StarsIn "Cate Blanchett" "The Fellowship of the Ring",
  StarsIn "Liv Tyler" "The Fellowship of the Ring"]

db :: MovieDB
db = (movies, stars, starsIn)

getMoviesLongerThan ::  Title -> MovieDB -> [Title]
getMoviesLongerThan title (m, s, si) = [ t1 | (Movie t y l) <- m , (Movie t1 y1 l1) <- m, l1 > l, t == title ]

getMaleActorsIn :: Title -> MovieDB -> [Name]
getMaleActorsIn title (m, s, si) = [n | (StarsIn n t) <- si , title == t, (MovieStar name gender) <- s, name == n, gender == 'M']

getFemaleActorsFrom :: Year -> MovieDB -> [Name]
getFemaleActorsFrom year (movies, stars, starsIn) = nub [n | (Movie x y z) <- movies , y == year, (StarsIn n t) <- starsIn, x == t, (MovieStar n' g') <- stars, g' == 'F' , n == n']