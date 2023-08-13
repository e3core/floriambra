// calcular el voltaje
/*const form = document.getElementById('form_voltage');

form.addEventListener("submit",(event)=>{
    event.preventDefault();
    const Corriente_one = document.getElementById('Corriente1');
    const Resistencia_one = document.getElementById('Resistencia1');
    const Corriente_number_one = parseFloat(Corriente_one.value);
    const Resistencia_number_one = parseFloat(Resistencia_one.value);   
    const result = document.createElement('p');
    let operacion = (Corriente_number_one+Resistencia_number_one)
    form.appendChild(result)
    result.innerHTML = `${operacion}`

    console.log(Corriente_number_one+Resistencia_number_one);
})
*/


const multiply_two = (number_one,number_two)=>{
    return number_one * number_two ;
}

const split_two = (number_one,number_two)=>{
    return number_one / number_two ;
}

function two_stage(form,box_one,box_two,calculation){

    const form_main = document.getElementById(form);

    form_main.addEventListener("submit",(event)=>{
        event.preventDefault();
        const variable_one = document.getElementById(box_one);
        const variable_two = document.getElementById(box_two);
        const number_one = parseFloat(variable_one.value);
        const number_two = parseFloat(variable_two.value);   
        const existingResults = form_main.querySelectorAll('p');
        existingResults.forEach((result) => {
            result.remove();
        });
        const result = document.createElement('p');
        result.classList.add("result_form");
        const total =  calculation(number_one,number_two);
        let  totalFixed = total.toFixed(2);
        totalFixed_total = parseFloat(totalFixed);
        if (totalFixed_total % 1 == 0) {
           totalFixed = totalFixed_total.toFixed(0);
        }
        form_main.appendChild(result)
        result.innerHTML = `${totalFixed}`
    
        console.log(totalFixed);
    })
    
}

two_stage('form_voltage','current1','endurance1',multiply_two);
two_stage('form_current','voltage2','endurance2',split_two);
two_stage('form_endurance','voltage3','current3',split_two);