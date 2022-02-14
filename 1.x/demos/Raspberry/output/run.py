import subprocess
import re

porta = "COM0"
tipoTransacao = str(2)
modoTransacao = str(1)
qtdParcelas = str(1)
valorTransacao = str(1050)
codigoEstabelecimento = "CODIGO002"

#result = subprocess.run(["/home/pi/plugpag/1.x/demos/Raspberry/output/CommandPromptTest", porta, tipoTransacao, modoTransacao, qtdParcelas, valorTransacao, codigoEstabelecimento], stdout=subprocess.PIPE)
result = subprocess.run(["/home/pi/plugpag/plugpag_python/arqui_c/output/totem", porta, tipoTransacao, modoTransacao, qtdParcelas, valorTransacao, codigoEstabelecimento], stdout=subprocess.PIPE)
message = result.stdout.splitlines()[2]
print(message)
message = (re.findall(r'\[(.*?)\]', str(message)) or None,)
print(message[0][0])