const http = require('http')
const server = http.createServer(onRequest)
server.listen(3000)
console.log('Servidor escuchando por el puerto 3000')

function onRequest(request,response){
    console.log('Servidor realizando peticion')
    const fs = require('fs')
    if (request.url == '/'){
        fs.readFile('D:/PROYECTOS-R/floriambra/e3core&floriambra/index.html',(err,content)=>{
            response.setHeader('content-type','text/html')
            response.write(content)
            response.end()
        })
    }
}

