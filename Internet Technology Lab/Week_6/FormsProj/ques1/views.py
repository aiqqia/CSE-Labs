from django.shortcuts import render
from .forms import TestForm

# Create your views here.
def index_view(request):
    tf = TestForm(request.POST or None)
    if request.method == 'POST':
        if tf.is_valid():
            context = {'firstInput':tf.cleaned_data['input1'], 'secondInput':tf.cleaned_data['input2']}
            return render(request,'ques1/output.html', context)
    return render(request,'ques1/index.html',{'content': tf})