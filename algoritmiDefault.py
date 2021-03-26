def operazione(x, y, tipo_operazione = "+"):    
    if tipo_operazione == "+":
        return x + y
    elif tipo_operazione == "-":
        return x - y
    elif tipo_operazione == "*":
        return x * y
    elif tipo_operazione == "/":
        return x / y
    else:
        return "ERRORE"


print(operazione(5, 4))         #fa la somma dato che come terzo parametro non c'è niente
print(operazione(5, 4, "-"))    #sottrazione