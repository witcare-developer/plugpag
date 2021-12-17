Demo do plugpag versão LINUX

Procedimento de instalação.

1) Baixe o pacote btserial-1.x.x.tar.gz e execute o script install.sh
2) Baixe o pacote plugpag-1.x.x.tar.gz e execute o script install.sh (neste momento é feito o pareamento com o terminal).
3) Baixe o pacote com a demo. Ja existe um binario pré-compilado CommandPromptTest.
4) Para compilar rode o comando make para gerar um novo binario
5) O binário será gerado em uma pasta output.
6) A variável LD_LIBRARY_PATH é utilizada por padrão pelo compilador gcc.
   O install.sh copia as libs para o dir /usr/local/lib por tanto para o gcc encontrar o caminho deve-se atribuir esse caminho à variável.
   Encontre o arquivo .bashrc e no final insira:
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib.
7) Execute no diretório output, criado pelo comando make, ./CommandPromptTest COM0 1 1 1 123 ABC.
   Atenção!!! não executar com sudo pois ele não encontra as libs.