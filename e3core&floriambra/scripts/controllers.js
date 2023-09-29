import { calculos } from "./calculations.js"
import { series_parall } from "./serie.js"


document.addEventListener('DOMContentLoaded', function() {
    const ohm_volt = new calculos('ohm_voltage',['current1','endurance1'],multiply_two,'V')
    const ohm_curr = new calculos('ohm_current',['voltage1','endurance2'],split_two,'A')
    const ohm_end = new calculos('ohm_endurance',['voltage2','current2'],split_two,'Ω')

    ohm_curr.two_stage()
    ohm_volt.two_stage()
    ohm_end.two_stage()
})

document.addEventListener('DOMContentLoaded',function(){
    const conductancia = new calculos('conductance',['conductance_1','endurance_conductance'],split_two,'S')
    const resistencia_conductor = new calculos('endurance_cond',['long-cond1','conduc_elect1','area_conduc1'],split_one_two,'Ω')
    const resistencia_conductor_two = new calculos('endurance_sp',['endurance_specify1','long_conduct1','are_conduct1'],split_two_one,'Ω')
    const conductibilidad = new calculos('conductibilidad',['conductibilidad_1','endurance_conductibilidad'],split_two,'s/m')

    conductancia.two_stage()
    resistencia_conductor.two_stage()
    resistencia_conductor_two.two_stage()
    conductibilidad.two_stage()
})

document.addEventListener('DOMContentLoaded',function(){
    const resistor_serie_one = new calculos('endurance_tension',['voltage_total1','voltage_measurement1','current_measurement1'],split_subtractiontwo_one,'Ω')
    const resistor_serie_two = new calculos('endurance_range',['range_apli1','range_numb1','endurance_interna1'],multiply_subtractiontwo_one,'Ω')
    const factor_range_one = new calculos('factor_range1',['voltage_total2','voltage_measurement2'],split_two,'')
    const factor_range_two = new calculos('factor_range2',['current_total1','current_measurement2'],split_two,'')
    
    resistor_serie_one.two_stage()
    resistor_serie_two.two_stage()
    factor_range_one.two_stage()
    factor_range_two.two_stage()
})

document.addEventListener('DOMContentLoaded',()=>{
    const serie = new series_parall('endurance_series','container_series1','endurance_amount1','enduranceamount_submit1',serie_addition)
    const parallel = new series_parall('endurance_parallel','container_parallel2','endurance_amount2','enduranceamount_submit2',parallel_addition)
    serie.serieParalls()
    parallel.serieParalls()
})

document.addEventListener('DOMContentLoaded',()=>{
    const resistor_temp = new calculos('endurance_variation',['temp_coefficient1','variation_temp1','endurance_ice1'],multiply_three,'Ω')
    const resistor_hot = new calculos('endurance_hot',['endurance_ice2','endurance_variation1'],addition,'Ω')
    const temperature_var = new calculos('temperature_variation',['endurance_hot1','endurance_ice3','temp_coefficient2','endurance_ice3'],addition_split_multiply,'')

    resistor_temp.two_stage()
    resistor_hot.two_stage()
    temperature_var.two_stage()
})




function multiply_two(number){
    const [numb_one,numb_two] = number
    return numb_one*numb_two
}

function split_two(number){
    const [number_one,number_two] = number
    return number_one/number_two
}

function split_one_two(number){
    const [numb_one,numb_two,numb_three] = number
    return numb_one/(numb_two*numb_three)
}

function split_two_one(number){
    const[numb_one,numb_two,numb_three] = number
    return (numb_one*numb_two)/numb_three
}

function split_subtractiontwo_one(number){
    const[numb_one,numb_two,numb_three] = number
    return (numb_one-numb_two)/numb_three
}

function multiply_subtractiontwo_one(number){
    const[numb_one,numb_two,numb_three] = number
    return (numb_one-numb_two)*numb_three
}

function serie_addition(number,value){
    return number + value
}

function parallel_addition(number,value){
    return ((value*number)/(value+number))
}

function multiply_three(number){
    const[numb_one,numb_two,numb_three] = number
    return(numb_one*numb_two*numb_three)
}

function addition(number){
    const [numb_one,numb_two] = number
    return(numb_one+numb_two)
}

function addition_split_multiply(number){
    const[numb_one,numb_two,numb_three,numb_four] = number
    return((numb_one+numb_two)/(numb_three*numb_four))
}