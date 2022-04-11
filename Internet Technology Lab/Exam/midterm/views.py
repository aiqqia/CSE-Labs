from django.shortcuts import render
import calendar

# Create your views here.
def index_view(request, year, choice):
    choice = int(choice)
    year = int(year)
    if(choice == 1):
        return render(request,'midterm/index1.html',{'content':f'Choice {choice}'})
    elif(choice == 2):
        #print(calendar.calendar(year))
        #return render(request,'midterm/index2.html',{'content':f'Choice {choice}: Calender of Year {year} will be displayed:'})
        return render(request,'midterm/index2.html',{'content':calendar.calendar(year)})
    else:
        return render(request,'midterm/index.html',{'content':'Wrong Choice!'})