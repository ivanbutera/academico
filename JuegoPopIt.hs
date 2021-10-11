-- 2° Trabajo Práctico del Taller de Álgebra 1
-- Iván Butera
-- 1C 2021


type Posicion = [Int]

type Jugada = (Int, Int)

type Set a = [a]

agregar :: Eq a => a -> Set a -> Set a
agregar x c | elem x c = c
            | otherwise     = x : c

union :: Eq a => Set a -> Set a -> Set a
union [] ys = ys
union (x:xs) ys = union xs (agregar x ys)

maximo :: [Int] -> Int
maximo (x:xs) | xs == [] = x
              | x > head xs = x
              | otherwise = maximo xs

quitar :: Eq a => a -> Set a -> Set a
quitar n l | n == head l = tail l
           | elem n (tail l) = (head l : quitar n (tail l))
           | otherwise = l


--
-- ejercicio 1
--

-- dado un indice i y una lista l, me indica el valor del elemento i-esimo de l
idValor :: Int -> [Int] -> Int                              
idValor i [] = 0                                              
idValor 1 l  = head l                                
idValor i l  = idValor (i-1) (tail l) 


--dado el indice i, reemplaza al i-esimo elemento de una lista l por un valor v
reemplazarValor :: Int -> Int -> [Int] -> [Int]                       
reemplazarValor _ _ [] = []
reemplazarValor i v (l:ls) | i == 1 = (v:ls)                              
                           | otherwise = l : (reemplazarValor (i-1) v ls)


-- dada una Posicion y una Jugada, devuelve la nueva posicion luego de jugar
jugar :: Posicion -> Jugada -> Posicion
jugar p (j1, j2) | r == 0 = quitar 0 (reemplazarValor j1 r p)
                 | otherwise = reemplazarValor j1 r p
               where r = (idValor j1 p)-j2


--
-- ejercicio 2
--

-- dada una Posicion y una Jugada, decide si la jugada se puede llevar a cabo
esJugValida :: Posicion -> Jugada -> Bool
esJugValida [] _       = False
esJugValida _ (0, _)   = False
esJugValida _ (_, 0)   = False
esJugValida p (j1, j2) | r < 0 = False
                       | otherwise = True
                      where r = (idValor j1 p)-j2


-- dada la Posicion, genera una lista con todas las jugadas (i,v) validas
generaJug :: Posicion -> Int -> Int -> Set Jugada
generaJug [] _ _ = []
generaJug p i v  | i > (length p) || v < 0 = []
                 | esJugValida p (i,v) = (i,v) `agregar` (generaJug p (i+1) v `union` generaJug p i (v-1))
                 | otherwise = generaJug p (i+1) v `union` generaJug p i (v-1)
                      

-- fijamos i = 1 y v = (max p)+1  para realizar la recursion sobre todos los posibles (i,v)
posiblesJugadas :: Posicion -> Set Jugada
posiblesJugadas p = generaJug p 1 (maximo p)


--
-- ejercicio 3
--

-- dada una posicion inicial p1, verifica las posibles posiciones resultantes p2 
esGanadora :: Posicion -> Set Jugada -> Bool
esGanadora  _   []   = False
esGanadora p1 (j:js) | not (esPosicionGanadora p2) = True
                     | otherwise = esGanadora p1 js
                   where p2 = jugar p1 j


-- la funcion pedida
esPosicionGanadora :: Posicion -> Bool
esPosicionGanadora [] = False
esPosicionGanadora  p = esGanadora p (posiblesJugadas p)                         


--                   
-- ejercicio 4
--

-- si jugar p por j es no-ganadora, devuelve j 
esJugadaGanadora :: Posicion -> Set Jugada -> Jugada
esJugadaGanadora p (j:js) | not(esPosicionGanadora p) = undefined
                          | not(esPosicionGanadora (jugar p j)) = j
                          | otherwise = esJugadaGanadora p js


-- la funcion pedida
jugadaGanadora :: Posicion -> Jugada
jugadaGanadora p = esJugadaGanadora p (posiblesJugadas p)


--
-- ejercicio 5
--

-- dada una posicion inicial p1, cuenta las jugadas tales que la resultante p2 sea no-ganadora
numJugGanAux :: Posicion -> Set Jugada -> Int
numJugGanAux _   []   = 0
numJugGanAux p1 (j:js) | not (esPosicionGanadora p2) = 1 + numJugGanAux p1 js
                       | otherwise = numJugGanAux p1 js
                     where p2 = jugar p1 j


-- la funcion pedida
numeroDeJugadasGanadoras :: Posicion -> Int
numeroDeJugadasGanadoras [] = 0
numeroDeJugadasGanadoras p = numJugGanAux p (posiblesJugadas p)