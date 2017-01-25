{-|
Module      : W
Description : Linear regression algorithm
Copyright   : (c) Maksymilian Wojczuk, 2017

Implementation of linear regression alghorithm.
Computing aproximation linear function ax + b = y for data set.
-}
module Regression
  ( regress,
    cost,
    getY
  ) where

-- |Linear Regression of one variable function
regress :: Fractional a => [a]   -- ^ First argument: list of arguments for some func
                        -> [a]   -- ^ Second argument: list of function results for corresponding argumets (first arg)
                        -> (a,a) -- ^ Resault: tuple representing a and b from ax + b = y
regress x y = gradient_descent (0,0) x y 0.01 (length x) 10000

{-|
returns distance between the function f(x) = theta_a * x + theta_b
and the given point for given x
-}
cost1el :: Fractional a => (a,a) -> a -> a -> a
cost1el (theta_a,theta_b) x_el y_el = (theta_a * x_el + theta_b - y_el) ^ 2

{-|
returns the sum of the cost of the function and a set of values
it is a sum of squares of distance between the given function and all of the given elements
-}
cost :: Fractional a => (a,a) -> [a] -> [a] -> a
cost theta x y = (1/(fromIntegral (length x))) * (foldl1 (+) (zipWith (cost1el theta) x y)) --suma kosztów dla każdego elementu pomnożona

{-|
simple loop of taking a gradient step
-}
gradient_descent :: (Fractional a, Num b, Eq b, Integral b) => (a,a) -> [a] -> [a] -> a -> b -> b -> (a,a)
gradient_descent (theta) _ _ _ _ 0 = (theta)
gradient_descent theta x y alpha xLength steps =
  gradient_descent (gradient_step theta x y alpha xLength) x y alpha xLength (steps - 1)

{-|
it is a step of a function into the minimum of the cost function (simple gradient)
-}
gradient_step :: (Fractional a, Num b, Eq b, Integral b) => (a,a) -> [a] -> [a] -> a -> b -> (a,a)
gradient_step (theta_a, theta_b) x y alpha xLength = (theta_a - (alpha * delta_a), theta_b - (alpha * delta_b)) where
  delta_a = 2/((fromIntegral xLength)) * (foldl1 (+) (zipWith (\ x_el y_el -> (theta_a * x_el + theta_b - y_el) * x_el) x y))
  delta_b = 2/((fromIntegral xLength)) * (foldl1 (+) (zipWith (\ x_el y_el -> theta_a * x_el + theta_b - y_el) x y))

{-|
returns a value of function (f(x) = theta_a * x + theta_b) for given x
-}
getY :: Fractional a => (a,a) -> a -> a
getY (theta_a, theta_b) x = theta_a * x + theta_b
