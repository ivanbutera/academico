-- TP n°1 del Taller de Álgebra
-- Iván Butera
-- 1C 2021.


-- EJERCICIO 1:
-- defino funciones auxiliares para chequear las condiciones de la conjetura de Goldbach

esPar :: Int -> Bool
esPar n = (mod n 2 == 0)

esMayorQue2 :: Int -> Bool
esMayorQue2 n = (n > 2)

menorDivisorDesde :: Int -> Int -> Int
menorDivisorDesde n k | (mod n k == 0)  = k
                      |  otherwise = menorDivisorDesde n (k+1)

menorDivisor :: Int -> Int
menorDivisor n = menorDivisorDesde n 2

esPrimo :: Int -> Bool
esPrimo n | (n == 1) = False
          | otherwise = (menorDivisor n == n)

minimoPrimoDesde n | esPrimo n = n
                   | not(esPrimo n) = minimoPrimoDesde (n+1)

nEsimoPrimo :: Int -> Int
nEsimoPrimo p | (p == 1) = 2
              | otherwise = minimoPrimoDesde(1 + nEsimoPrimo (p-1))


anteriorPrimoHasta :: Int -> Int -> Int
anteriorPrimoHasta n k | (nEsimoPrimo n < k) = nEsimoPrimo n
                       | (nEsimoPrimo n == k) = k
                       |  otherwise = anteriorPrimoHasta (n-1) k

anteriorPrimo :: Int -> Int
anteriorPrimo k = anteriorPrimoHasta (k-1) k


esSumaPrimos :: Int -> Bool                            -- hace la recursion sobre i, que definimos
esSumaPrimos n | esPrimo(n - i) = True                  -- como el primo anterior a n
               | otherwise = esPrimo(n - (i-2))
                 where i = anteriorPrimo n


satisfaceGoldbach :: Int -> Bool
satisfaceGoldbach n = ((esPar n && esMayorQue2 n) && (esSumaPrimos n))




-- EJERCICIO 2:

verificarConjeturaHasta :: Int -> Bool                              -- si n satisface goldbach, chequeamos
verificarConjeturaHasta n | n < 4 || not(esPar n) = False           -- que n-2 lo haga, y asi la recursion
                          | n == 4 = True
                          | satisfaceGoldbach n = verificarConjeturaHasta (n-2)



-- EJERCICIO 3:

descAux :: Int -> Int -> (Int, Int)                                    -- crea una tupla de numeros primos
descAux p n | n == 2 || not(esPar n) = undefined                         -- cuya suma es n. si no funciona, 
            | (esPrimo p && esPrimo (n-p)) = (p, (n-p))                   -- intenta con un primo menor
            | otherwise = descAux (p-2) n


descomposicionEnPrimos :: Int -> (Int, Int)                           -- fijamos el primo como el 
descomposicionEnPrimos n = descAux (anteriorPrimo n) n             -- primo inmediatamente anterior a n




-- EJERCICIO 4:

esDescDePrimos :: Int -> (Int, Int) -> Bool                               -- chequea que una tupla dada 
esDescDePrimos n (p, q) = (esPrimo p && esPrimo q) && (p + q == n)        -- sea descomposicion de n


numDescAux :: Int -> Int -> Int
numDescAux _ 4 = 1
numDescAux i n | i < 3 = 0                                                  -- crea la tupla dado un i 
               | esDescDePrimos n (n-i, i) = 1 + numDescAux (i-2) n         -- menor a n, si no es descomposicion
               | otherwise = numDescAux (i-2) n                              -- entonces intenta con un i anterior        


numeroDeDescomposiciones :: Int -> Int                                      -- fijamos i como el anterior 
numeroDeDescomposiciones n | n < 4 || not(esPar n) = undefined              -- primo a n, y queda la funcion
                           | otherwise = numDescAux (anteriorPrimo n) n                 



-- EJERCICIO 5 

comparaDesc :: Int -> Int -> Int
comparaDesc a b | numeroDeDescomposiciones a < numeroDeDescomposiciones b = b     -- comparamos dos numeros a ver cual
                | numeroDeDescomposiciones a > numeroDeDescomposiciones b = a     -- es mas descomponible, y si hay
                | otherwise = min a b                                               -- "empates" nos da el mas chico



másDescomponible :: Int -> Int
másDescomponible 4 = 4                                          -- dado n compara su num de descomposiciones                    
másDescomponible n = comparaDesc n (másDescomponible (n-2))     -- con el de (n-2) y asi hasta llegar al 
                                                                 -- caso base (4), y los compara 2 a 2
                                                                       
