from django.shortcuts import render
from .models import Product, ProductForm, Question, Option
from datetime import datetime

# Create your views here.
def form_view(request):
    pf = ProductForm(request.POST or None)
    if request.method == 'POST':
        if pf.is_valid():
            product = pf.save(commit = False)
            product.timestamp = datetime.now()
            product.save()
            return render(request,'app1/product.html',{'product':product})
    return render(request,'app1/index.html',{'pf':pf})

def products_view(request):
    products = Product.objects.all()
    return render(request,'app1/allproducts.html',{'products':products})

def ques_view(request):
    if request.method == "POST":
        question = Question.objects.all()
        optionSelected = request.POST['question']
        print(optionSelected)
        option = Option.objects.filter(value=optionSelected)[0]
        print(option)
        option.number += 1
        option.save()
        options = Option.objects.all()
        return render(request,'app1/form.html',{'options':options})
    question = Question.objects.all()
    return render(request,'app1/form.html',{'question':question[0].question, 'options':question[0].options.all()})