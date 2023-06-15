const express = require('express')
const app = express()
const path = require('path')
const port = 5005

// Configura la carpeta pública para archivos estáticos
app.use(express.static(path.join(__dirname, '../e3core&floriambra')));

app.get('/',(request,response)=> {
    const filePath = path.join(__dirname, '../e3core&floriambra/index.html')
    response.sendFile(filePath)
})

app.listen(port,()=> {
    console.log('mi aplicacion esta corriendo por el puerto 5005')
})