from django.shortcuts import render

# Create your views here.
def index_view(request):
    return render(request,'ques4/index.html',{'content':'this is q4'})
