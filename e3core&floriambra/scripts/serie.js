export class series_parall{
    constructor(id_form,id_form2,id_input,id_submit,function_form){
        this.id_form = id_form,
        this.id_form2 = id_form2,
        this.id_input = id_input,
        this.id_submit = id_submit,
        this.function_form = function_form
    }

    serieParalls(){
        let count = 0
        let arreglo = []
        let value = 0
        let counter = 0
        const form = document.getElementById(this.id_form)
        const container = document.getElementById(this.id_form2)
        const form_input = document.getElementById(this.id_input)
        const form_submit = document.getElementById(this.id_submit)
        const form_calc = document.createElement('form')
        const input = document.createElement('input')
        const submit = document.createElement('input')
        const button = document.createElement('button')
        const paragraph = document.createElement('p')
        button.setAttribute('text','reset')
        button.innerHTML = 'reset'
        submit.setAttribute('type','submit')
        submit.value = 'ok'
    
        form.addEventListener('submit',(e)=>{
            e.preventDefault()
            counter = form_input.value
            console.log(form_input.value)
            container.appendChild(form_calc)
            form_calc.appendChild(input)
            form_calc.appendChild(submit)
            form_calc.appendChild(button)
            form_submit.setAttribute('class','disguise')
            })
    
            form_calc.addEventListener('submit',(a)=>{
                a.preventDefault()
                value =  parseFloat(input.value)
                arreglo.push(value)
                form_calc.reset()
                count++
                console.log(counter)
                if(count == counter){
                    let numb = 0
                    for(let i=0;i<arreglo.length-1;i++){
                        if(numb === 0){
                            numb = value
                        }
                        numb = this.function_form(arreglo[i],numb)
                    }
                    paragraph.innerHTML = `${numb}`
                    form_calc.appendChild(paragraph)
                    arreglo = null
                    arreglo = []
                    count = 0
                    
                }
            })
    
            button.addEventListener('click',()=>{
                location.reload()
            })
    }
}


