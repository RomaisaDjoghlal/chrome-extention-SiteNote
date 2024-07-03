
const inputBtn = document.getElementById("input-btn");
let myLeads = [] ;
const inputEl = document.getElementById("input-el");
const ulEl = document.getElementById("ul-el");
const deleteBtn = document.getElementById("delete-btn");
const tabBtn = document.getElementById("tab-btn");


//json is data represanting format

const leadsFromLocalStorage = JSON.parse( localStorage.getItem("myLeads"))

if (leadsFromLocalStorage) {
  myLeads = leadsFromLocalStorage
  render(myLeads)
 }
 


     
     


         function render(leads) {
          let listItems = "";
          for (let i = 0; i < leads.length; i++) {
            const lead = leads[i];
            if (typeof lead === "string") {
              // For plain text (strings), display as plain list item
              listItems += `<li>${lead} :`;
            } else if (typeof lead === "object" && lead.url && lead.text) {
              // For objects with URL and text properties, display as clickable link
             
            listItems += `  <a target='_blank' href='  ${lead.url}'>  ${lead.text}</a> </li>`;
            
             
              
            }
          }
          ulEl.innerHTML = listItems;
        }

        
        
        inputBtn.addEventListener("click",function(){

        myLeads.push(inputEl.value);
        // Clear out the input field
        inputEl.value = "" ;
          // Save the myLeads array to localStorage 
          // PS: remember JSON.stringify() cuz it has to be string in the localstorage
          /* JSON.stringify() before storing it in LocalStorage. When retrieving the data,
           JSON.parse() is used to convert the JSON string back to its original JavaScript object. */
          
          localStorage.setItem("myLeads",JSON.stringify(myLeads)) ;
          render(myLeads)

        })
        

        

        tabBtn.addEventListener("click", function () {
          chrome.tabs.query({ active: true, currentWindow: true }, function (tabs) {
            const tabData = { url: tabs[0].url, text: tabs[0].title };
            myLeads.push(tabData);
            localStorage.setItem("myLeads", JSON.stringify(myLeads));
            render(myLeads);
          });
        });



        

        
        

      deleteBtn.addEventListener("dblclick",function(){
        localStorage.clear();  
        myLeads = [];
        render(myLeads); 

      })

      // the role of json  facilitating data transfer and communication between applications.



      