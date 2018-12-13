#!/bin/bash

echo "Content-type: text/html"
echo ""
echo '<HTML><HEAD><meta charset="UTF-8">'
echo '<TITLE>Pagina CGI gerando figura</TITLE></HEAD>'
echo '<BODY style="background-color:#FFFFE0"><H1>Relatório Web</H1>'
echo 'Estou no diretório '
pwd
echo ', logado como o usuário '
whoami
echo '.<br>'
echo '<h2>DADOS:</h2>'
echo '<pre>'
echo '</pre>'
echo '<br>'
echo '<br>'
echo '<h2>IMAGENS:</h2>'
echo 'Referenciando a imagem como "/usr/local/bin/imagemscreen.cgi":<br>'
echo '<img src="/usr/local/bin/imagemscreen.cgi">'
echo '<br>'
echo '</HTML>'

