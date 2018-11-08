CONTADOR = 0

def inserta(x, lst, i):
	global CONTADOR
	CONTADOR = CONTADOR+1
	return lst[:i] + [x] + lst[i:]

def inserta_multiple(x, lst):
	return [inserta(x, lst, i) for i in range(len(lst) + 1)]

def permuta(c):
	if len(c) == 0:
		return [[]]
	
	return sum([inserta_multiple(c[0], s)
                for s in permuta(c[1:])],[])

print(permuta([1,2,3]),"LLAMADAS RECURSIVAS: ",CONTADOR)            