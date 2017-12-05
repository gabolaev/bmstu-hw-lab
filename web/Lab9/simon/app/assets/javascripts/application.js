// This is a manifest file that'll be compiled into application.js, which will include all the files
// listed below.
//
// Any JavaScript/Coffee file within this directory, lib/assets/javascripts, or any plugin's
// vendor/assets/javascripts directory can be referenced here using a relative path.
//
// It's not advisable to add code directly here, but if you do, it'll appear at the bottom of the
// compiled file. JavaScript code in this file should be added after the last require_* statement.
//
// Read Sprockets README (https://github.com/rails/sprockets#sprockets-directives) for details
// about supported directives.
//
// = require rails-ujs
// = require turbolinks
// = require jquery
// = require_tree .

function show_result(data) {
    $('#results').empty();
    let result = document.getElementById("results");
    let header = document.createElement('h2');
    result.appendChild(header);
    if (data.error === true){
        header.innerHTML = `Ошибка формата входных данных.`;
        return;
    }
    header.innerHTML = `По результатам вычислений найдено ${data.results.length} таких факториалов. <br> А именно:`;
    data.results.forEach(function (iter) {
        let itersValue = document.createElement('p');
        itersValue.innerText = `${iter}`;
        result.appendChild(itersValue)
    });

    let zipped = data.for_facts.map(function (himself, iter) {
        return [himself, data.iters[iter]]
    });

    let lookBottom = document.createElement('h3');
    result.appendChild(lookBottom);
    lookBottom.innerText = 'Ниже расположены все рассчёты.';
    let table = document.createElement('table');
    table.style.cssText = `border: solid 2px black; border-collapse: collapse;`
    result.appendChild(table);
    zipped.forEach(function (pair, index) {
        let row = table.insertRow(-1);
        let infoCell = row.insertCell(0);
        let calculationsCell = row.insertCell(1);
        [infoCell, calculationsCell].forEach(function(element){
            element.style.cssText = `text-align: center; border: 2px solid black;`
        });
        infoCell.innerText = `${index + 3}! = ${pair[0]}`;
        for (let i in pair[1]) {
            let calc = document.createElement('p');
            calc.innerText = `${pair[1][i]}`;
            calculationsCell.appendChild(calc);
        }
    });


}

$(document).ready(function () {
    $('#input_form').bind("ajax:success", function (xrs, data, status) {
        show_result(xrs.detail[0]);
        console.log(xrs.detail[0]);
    })
});
