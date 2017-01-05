module KMP
    ( findPattern
    ) where

data FailureTable a = FailureTable {
    done :: Bool,                           --If this is the end of the pattern
    next :: (a -> FailureTable a)           --What to do with the next character from data where we are looking for pattern
}

{-
First argument: pattern
Second argument: data where to find pattern
Resault: List of indexes where pattern starts in data
-}
findPattern :: Eq a => [a] -> [a] -> [Int]

makeFailureTable :: Eq a => [a] -> FailureTable a
makeFailureTable xs = table   --table is base case. Begining of the pattern
  where table = makeFailureTable' xs (const table)    --(const:: a->b->a) it is next for base fail case

makeFailureTable' :: Eq a => [a] -> (a -> FailureTable a) -> FailureTable a
makeFailureTable' [] ifFail = FailureTable True ifFail      --we are at the end of pattern so done is True
makeFailureTable' (x:xs) ifFail = FailureTable False test
  where test c = if c == x then success else ifFail c       --if character isn't correct match it to fail function
        success = makeFailureTable' xs (next (ifFail x))    --if character is correct return next position of FailureTable where
                                                            --fail function is fail function computed for this character (which is the same like letter in the pattern)

findPattern pattern xs = match (makeFailureTable pattern) xs ((length pattern) * (-1))   -- -(length pattern) as starting position because True in FailureTable will be exactly (length pattern) characters from place where patern starts in data
  where match table [] pos = if done table then [pos] else []     --at the end of data there is chceck if last character didn't complet pattern
        match table (x:xs) pos = if done table then [pos] ++ match (next table x) xs (pos+1) else match (next table x) xs (pos+1)
        -- if pattenr is completed than mark index where pattern started in data. Second part is same in both case, match rest of data to pattern
