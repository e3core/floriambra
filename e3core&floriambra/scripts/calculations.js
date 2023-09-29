export class calculos{
    constructor(id_form,id,calculation,extension){
        this.id_form = id_form,
        this.id = id,
        this.calculation = calculation,
        this.extension = extension
    }

    two_stage(){
        const form_main = document.getElementById(this.id_form);
        form_main.addEventListener("submit",(event)=>{
            event.preventDefault();
            let element = [];
            let number = [];
            let item = [];
            element = this.id;
            console.log(element)
            element.map((id)=>{
                item.push(document.getElementById(id))
                console.log(item)
            })               
            item.map((id)=>{
                let parse = 0
                parse = parseFloat(id.value)
                number.push(parse)
            })
            const existingResults = form_main.querySelectorAll('p');
            existingResults.forEach((result) => {
                result.remove();
            });
            const result = document.createElement('p');
            result.classList.add("result_form");
            const total =  this.calculation(number);
            let  totalFixed = total.toFixed(2);
            let totalFixed_total = parseFloat(totalFixed);
            if (totalFixed_total % 1 == 0) {
                totalFixed = totalFixed_total.toFixed(0);
            }
            form_main.appendChild(result)
            result.innerHTML = `${totalFixed} ${this.extension}`    
        })
    }
}
