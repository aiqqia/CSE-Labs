from django.shortcuts import render

def home_view(request):
    return render(request,'WebPage1.html',{'content':'Enter Year and Choice in your browser link!'})