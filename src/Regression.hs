-- regresja liniowa funkcji jednej zmiennej
module Regression
  ( regress,
    cost,
    getY
  ) where

cost1el :: Fractional a => (a,a) -> a -> a -> a
cost1el (theta_a,theta_b) x_el y_el = (theta_a * x_el + theta_b - y_el) ^ 2

-- Obecny koszt prostej względem zbioru (suma kwadratow odległości kazdego z elementow od prostej)
cost :: Fractional a => (a,a) -> [a] -> [a] -> a
cost theta x y = (1/(fromIntegral (length x))) * (foldl1 (+) (zipWith (cost1el theta) x y))


gradient_descent :: (Fractional a, Num b, Eq b) => (a,a) -> [a] -> [a] -> a -> b -> (a,a)
gradient_descent (theta) _ _ _ 0 = (theta)
gradient_descent theta x y alpha steps =
  gradient_descent (gradient_step theta x y alpha) x y alpha (steps - 1)

-- ruch o 'alpha' w kierunku minimum funkcji kosztu
gradient_step :: Fractional a => (a,a) -> [a] -> [a] -> a -> (a,a)
gradient_step (theta_a, theta_b) x y alpha = (theta_a - (alpha * delta_a), theta_b - (alpha * delta_b)) where
  delta_a = 2/((fromIntegral (length x))) * (foldl1 (+) (zipWith (\ x_el y_el -> (theta_a * x_el + theta_b - y_el) * x_el) x y))
  delta_b = 2/((fromIntegral (length x))) * (foldl1 (+) (zipWith (\ x_el y_el -> theta_a * x_el + theta_b - y_el) x y))

regress :: Fractional a => [a] -> [a] -> (a,a)
regress x y = gradient_descent (0,0) x y 0.01 10000

getY :: Fractional a => (a,a) -> a -> a
getY (theta_a, theta_b) x = theta_a * x + theta_b
