
import subprocess

result = subprocess.run(["sudo", "rfcomm", "-i", "show"], stdout=subprocess.PIPE)
print(result.stdout)

if result.stdout == b'':
    print("Pressione a tecla zero.")
    result = subprocess.run(["sudo", "hcitool", "scan"], stdout=subprocess.PIPE)
    array = result.stdout.split()
    print(array[2])

    result = subprocess.run(["sudo", "rfcomm", "release", "all"], stdout=subprocess.PIPE)
    result = subprocess.run(["sudo", "rfcomm", "bind", "/dev/rfcomm0", array[2], "1"], stdout=subprocess.PIPE)
    result = subprocess.run(["sudo", "chmod", "777", "/dev/rfcomm0"], stdout=subprocess.PIPE)
    print("Configurado com sucesso.\nPressione a tecla Sair da maquininha para voltar a tela principal.")
else:
    print("Porta ja configurada.")