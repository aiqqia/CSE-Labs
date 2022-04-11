from django.shortcuts import render

def index_view(request):
    return render(request,'index.html',{'content':'Select which question to go to in the link above!'})
