import Test.QuickCheck
import Quicksort
import MergeSort
import Data.List
import Test.HUnit
import KMP

-- main :: IO ()
main = do
  quickCheck prop_merge
  quickCheck prop_mergeSort
  quickCheck prop_partFromQS
  runTestTT testMerge
  runTestTT testKMP


-- prop_merge :: [Int] -> [Int] -> Bool
prop_merge n m = (merge (sort n) (sort m)) == (sort (n ++ m))
  where types = (n :: [Int], m :: [Int])


-- nie wiem, czy tak mogę, bo mergeSort uzywa funkcji merge, skad nie jest to test jednostkowy metody
-- prop_mergeSort :: [Int] -> Bool
prop_mergeSort n = (mergeSort n) == (sort n)
  where types = n :: [Int]

-- przez to ze wrzucasz na poczatek listy w tej funkcji, to trzeba reversowec w testach
prop_partFromQS xs y = (part xs y) == (reverse (filter (> y) xs), reverse (filter (== y) xs), reverse (filter (< y) xs))
  where types = (xs :: [Int], y :: Int)

testKMP :: Test
testKMP = TestCase $ assertEqual "Should give list of indexes where string test is" [16] (findPattern "test" "icuasdjvnacvadfitesttetetetetetstststetrteteset")

testMerge :: Test
testMerge = TestCase $ assertEqual "should give a sorted list" [1..1000] (mergeSort [1..1000])
